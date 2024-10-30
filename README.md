# Physical Computing Project 2024 - IT KMITL 
## Smoke Detector
โครงงานนี้เป็นส่วนหนึ่งของวิชา Physical Computing โดยมีวัตถุประสงค์เพื่อศึกษาและพัฒนาทักษะการเขียนโปรแกรมภาษา C และการใช้งานบอร์ด Arduino ทั้งจากการเรียนรู้ในห้องเรียนและการศึกษาเพิ่มเติมด้วยตนเอง คณะผู้จัดทำหวังเป็นอย่างยิ่งว่าโครงงานนี้จะเป็นประโยชน์แก่ผู้ที่สนใจศึกษาและสามารถนำไปพัฒนาต่อยอดเพื่อความสมบูรณ์และประสิทธิภาพที่ดียิ่งขึ้นในอนาคต
## สารบัญ

 - [Poster](#Poster)
 - [ที่มาของโครงงาน](#%E0%B8%97%E0%B8%B5%E0%B9%88%E0%B8%A1%E0%B8%B2%E0%B8%82%E0%B8%AD%E0%B8%87%E0%B9%82%E0%B8%84%E0%B8%A3%E0%B8%87%E0%B8%87%E0%B8%B2%E0%B8%99)
 - [จุดประสงค์](#%E0%B8%88%E0%B8%B8%E0%B8%94%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B8%AA%E0%B8%87%E0%B8%84%E0%B9%8C)
 - [ประโยชน์](#%E0%B8%9B%E0%B8%A3%E0%B8%B0%E0%B9%82%E0%B8%A2%E0%B8%8A%E0%B8%99%E0%B9%8C)
 - [อุปกรณ์](#%E0%B8%AD%E0%B8%B8%E0%B8%9B%E0%B8%81%E0%B8%A3%E0%B8%93%E0%B9%8C)
 - [หลักการทำงาน](#%E0%B8%AB%E0%B8%A5%E0%B8%B1%E0%B8%81%E0%B8%81%E0%B8%B2%E0%B8%A3%E0%B8%97%E0%B8%B3%E0%B8%87%E0%B8%B2%E0%B8%99)
 - [Youtube สาธิตการทำงาน](#Youtube-%E0%B8%AA%E0%B8%B2%E0%B8%98%E0%B8%B4%E0%B8%95%E0%B8%81%E0%B8%B2%E0%B8%A3%E0%B8%97%E0%B8%B3%E0%B8%87%E0%B8%B2%E0%B8%99)
 - [Member](#Member)

## Poster

![](https://private-user-images.githubusercontent.com/141398352/381258459-686b7416-bc2c-49ac-8347-30e00d6c99d0.jpg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzAyOTA5NDgsIm5iZiI6MTczMDI5MDY0OCwicGF0aCI6Ii8xNDEzOTgzNTIvMzgxMjU4NDU5LTY4NmI3NDE2LWJjMmMtNDlhYy04MzQ3LTMwZTAwZDZjOTlkMC5qcGc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQxMDMwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MTAzMFQxMjE3MjhaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT04YzI5ZGMzNmFiYmJhNTRmZmU2MzMyYzNiNzhlYWYyYjU0ZDYwNjAxOGUxNmU0NGVmNzAwZWEyZTkwNjYxNTJhJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.19xeoWQyaTeAv2iHiFcyBdm8eNO3CkGvIj6iOiVtauM)

## ที่มาของโครงงาน
ปัจจุบัน การเกิดเพลิงไหม้เป็นอันตรายใกล้ตัวที่มักทำให้ผู้คนทราบถึงเหตุการณ์เมื่อเพลิงไหม้ลุกลามไปแล้ว ทางคณะผู้จัดทำได้ตระหนักถึงปัญหานี้ จึงได้นำความรู้เกี่ยวกับ Arduino มาพัฒนาโครงงานเครื่องตรวจจับควัน ซึ่งสามารถส่งข้อความแจ้งเตือนผ่านแอปพลิเคชัน Line เพื่อให้สามารถป้องกันการลุกลามของเพลิงไหม้ได้อย่างทันท่วงที
## จุดประสงค์

 -   เพื่อศึกษาการเขียนโปรแกรมภาษา C ในการควบคุมเซนเซอร์และอุปกรณ์ต่าง ๆ บนบอร์ด Arduino
 -   เพื่อออกแบบและสร้างเครื่องตรวจจับควันด้วย Arduino ที่สามารถตรวจจับควันและแจ้งเตือนผู้ใช้เมื่อเกิดควันไฟ
 -   เพื่อพัฒนาเครื่องตรวจจับควันที่สามารถส่งข้อความเตือนผ่านแอปพลิเคชัน Line เพื่อแจ้งเหตุไฟไหม้ได้ทันที
 -   เพื่อเพิ่มความสามารถในการป้องกันและลดความเสี่ยงจากการเกิดเพลิงไหม้ในอาคารหรือสถานที่ต่าง ๆ
 -   เพื่อสร้างโครงงานที่สามารถนำไปพัฒนาต่อยอดให้เกิดความสมบูรณ์และประสิทธิภาพมากยิ่งขึ้น

## ประโยชน์
-   ช่วยลดความเสี่ยงจากการเกิดเพลิงไหม้ ด้วยการตรวจจับควันได้อย่างรวดเร็วและแจ้งเตือนทันที
-   เพิ่มความปลอดภัยในบ้านหรือสถานที่ทำงาน โดยเฉพาะในกรณีที่ผู้ใช้งานไม่สามารถมองเห็นหรือได้กลิ่นควัน
-   ลดความเสียหายต่อชีวิตและทรัพย์สิน ด้วยการแจ้งเตือนก่อนที่เพลิงไหม้จะลุกลาม
-   เป็นต้นแบบสำหรับการศึกษาและพัฒนาระบบตรวจจับและเตือนภัยที่มีประสิทธิภาพมากยิ่งขึ้น
-   ส่งเสริมการเรียนรู้ด้าน Physical Computing, การเขียนโปรแกรม C, และการใช้งานบอร์ด Arduino เพื่อประยุกต์ใช้ในชีวิตประจำวัน
## อุปกรณ์

1. Arduino UNO

![enter image description here](https://res.cloudinary.com/rsc/image/upload/b_rgb:FFFFFF,c_pad,dpr_2.625,f_auto,h_535,q_auto,w_950/c_pad,h_535,w_950/Y2662937-01?pgw=1&pgwact=1)

2. LED

![enter image description here](https://inwfile.com/s-fw/qvw8pv.jpg)

 3. Jumper Wires

![enter image description here](https://res.cloudinary.com/rsc/image/upload/b_rgb:FFFFFF,c_pad,dpr_2.625,f_auto,h_535,q_auto,w_950/c_pad,h_535,w_950/R2048239-01?pgw=1&pgwact=1)

 4. MQ-2 Smoke Gas Sensor

![enter image description here](https://www.tido.tech/wp-content/uploads/2020/09/l1.jpg)
## หลักการทำงาน
```1. ให้ต่ออุปกรณ์แล้ว อัพโหลดโค้ดลง Arduino uno```

```2. รออุปกรณ์ Calibrating ประมาณ 2 3 วินาที```

```3. ค่าที่ขึ้นมาจะมีเป็น 0 ทั้งหมด เพราะยังไม่มีการเกิดควัน```

```4. ตรวจจับควัน ถ้าเราจะตรวจจับแก็สมีเทน ให้เรากดไฟแช็คแล้วนำไปวางใกล้ๆ เซ็นเซอร์ตรวจจับควัน MQ2 ค่า LPG , CO , SMOKE ที่อ่านได้จะสูงขึ้น```

![](https://scontent.xx.fbcdn.net/v/t1.15752-9/462554086_1557402625138891_4763458699626586356_n.png?_nc_cat=104&ccb=1-7&_nc_sid=0024fc&_nc_ohc=Q4tGE15pgogQ7kNvgFQ27ye&_nc_ad=z-m&_nc_cid=0&_nc_zt=23&_nc_ht=scontent.xx&_nc_gid=AHY-NCJtti_zkYgw70NTbzq&oh=03_Q7cD1QHN1Yyu7jEGEdt5Feihe246f188XNjiNM3KX2AAjrMfGg&oe=67486901)

```5. ถ้าค่า LPG , CO , SMOKE เกินค่าที่กำหนด ไฟ LED จะขึ้น และมีการแจ้งเตือนผ่าน LINE Application```

![](https://scontent.xx.fbcdn.net/v/t1.15752-9/462543867_1480297235979431_6388037079702809891_n.jpg?_nc_cat=109&ccb=1-7&_nc_sid=0024fc&_nc_ohc=JLCSb81f3v0Q7kNvgHHGqZ0&_nc_ad=z-m&_nc_cid=0&_nc_zt=23&_nc_ht=scontent.xx&_nc_gid=AHY-NCJtti_zkYgw70NTbzq&oh=03_Q7cD1QEh4haPQXXTTbjb7Wrw6AlBjsB7NJmWhgTeAcSMmJLt4g&oe=67484077)

## Youtube สาธิตการทำงาน
https://www.youtube.com/watch?v=SjFC09XNLUY
## Member

`นายกฤษดา เอนกธนกุล 66070007`

`นายชินกิจ ฤกษ์ดี 66070048`

`นายฐาปนพงศ์ พงษ์บริบูรณ์ 66070053`

`นายองศา เทียนชัย 66070212`

รายงานนี้เป็นส่วนหนึ่งของวิชา Physical Computing ภาคเรียนที่ 1 ปีการศึกษา 2567 สาขาเทคโนโลยีสารสนเทศ คณะเทคโนโลยีสารสนเทศ สถาบันเทคโนโลยีพระจอมเกล้าเจ้าคุณทหารลาดกระบัง
