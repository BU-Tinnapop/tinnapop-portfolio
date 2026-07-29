# Cyber Security Portfolio — HTML / CSS / JavaScript

เว็บ Portfolio แบบหน้าเดียว เปิดใช้งานได้ทันทีและไม่ต้องติดตั้งโปรแกรมเสริม มี Home, About, Skills, Projects, Activities, Certificates, Experience และ Contact พร้อม responsive layout, mobile menu, dark/light mode, animation, project filtering, modal, certificate lightbox และปุ่มกลับด้านบน

ลูกเล่นด้านภาพและการโต้ตอบเพิ่มเติมอยู่ใน `enhancements.css` และส่วนท้ายของ `script.js` ประกอบด้วยแสงตามเมาส์ การ์ดโปรไฟล์แบบ tilt, hover glow, พื้นหลังเคลื่อนไหว และ navbar เมื่อเลื่อนหน้า หากต้องการปิดเฉพาะงานตกแต่ง ให้ลบลิงก์ `enhancements.css` ใน `index.html` และลบส่วนที่ขึ้นต้นด้วย `// ลูกเล่นเสริม` ใน `script.js`

ปุ่ม `EN / TH` บนแถบเมนูใช้สลับภาษาไทยและอังกฤษ ระบบจะจดจำภาษาที่เลือกในเบราว์เซอร์ ข้อความแปลอยู่ใน `translation.js` และสามารถแก้ไขหรือเพิ่มคำแปลได้จากตัวแปร `translations`

## วิธีเปิดเว็บ

1. แตกไฟล์ ZIP (ถ้าดาวน์โหลดแบบ ZIP)
2. เปิด `index.html` ด้วย Chrome, Edge หรือ Firefox
3. ถ้าต้องการทดสอบแบบ local server ใช้ส่วนขยาย Live Server ใน VS Code แล้วเลือก **Open with Live Server**

## จุดที่ต้องแก้ก่อนส่งอาจารย์

ค้นหาคำต่อไปนี้ในทุกไฟล์ แล้วแทนด้วยข้อมูลจริง:

- `YOUR NAME` — ชื่อ-นามสกุล
- `YOUR MAJOR` — สาขาวิชา
- `YOUR UNIVERSITY` — มหาวิทยาลัย
- `YOUR_USERNAME` — username ของ GitHub/LinkedIn
- `you@example.com` — อีเมล (ต้องแก้ทั้ง `index.html` และ `script.js`)

ข้อมูลตัวอย่างของ Projects, Activities, Certificates และ Experience อยู่ใน `index.html` ส่วนรายละเอียด modal ของ Projects อยู่ในตัวแปร `projects` ภายใน `script.js`

## เปลี่ยนรูปโปรไฟล์และรูปกิจกรรม

เว็บใช้ภาพกราฟิก placeholder เพื่อให้เปิดแล้วไม่พบรูปเสีย หากต้องการใช้ภาพจริง:

1. นำรูปไปไว้ในโฟลเดอร์ `assets/images/`
2. รูปโปรไฟล์ปัจจุบันอยู่ที่ `assets/images/profile.jpg` หากต้องการเปลี่ยน ให้ใช้ชื่อไฟล์เดิมแทนรูปปัจจุบัน
3. รูปกิจกรรมสามารถเปลี่ยน `<div class="activity-img ...">...</div>` เป็น `<img class="activity-img" src="assets/images/activity-1.jpg" alt="คำอธิบายกิจกรรม">`

ใช้ชื่อไฟล์ภาษาอังกฤษ ตัวพิมพ์เล็ก และไม่เว้นวรรค เช่น `ctf-competition.jpg` ขนาดรูปแนะนำ 1600×900 px และบีบอัดให้ไม่เกินประมาณ 500 KB

## ใบรับรอง

ใบรับรองจริง 7 ใบอยู่ใน `assets/certificates/` และเชื่อมกับการ์ดในส่วน Certifications แล้ว เมื่อกดการ์ด ระบบจะแสดงไฟล์ในหน้าต่าง Lightbox พร้อมปุ่มเปิดหรือดาวน์โหลด ใบ `Test-Non-Proctored-Federation Test` ไม่ได้นำมาใส่เพราะเป็นใบสำหรับการทดสอบระบบ ไม่ใช่ Certification สำหรับนำเสนอผลงาน

## Contact form

เวอร์ชันนี้ไม่เก็บข้อมูลและไม่ต้องมี backend เมื่อกดส่งจะเปิดโปรแกรมอีเมลของผู้ชม ถ้าต้องการส่งจากหน้าเว็บโดยตรง ให้เชื่อม Formspree, EmailJS หรือ backend ของตนเอง และอย่าใส่ API secret ไว้ใน JavaScript ฝั่งผู้ใช้

## เผยแพร่ฟรี

- **GitHub Pages:** อัปโหลดไฟล์ทั้งหมดเข้า repository แล้วเปิด Pages จาก Settings
- **Netlify:** ลากโฟลเดอร์โปรเจกต์เข้า Netlify Drop
- **Vercel:** Import repository แล้วตั้งค่าเป็น Static site โดยไม่ต้องมี build command

ตรวจทุกลิงก์ ข้อมูลส่วนตัว การสะกด และการแสดงผลบนมือถือก่อนส่งหรือเผยแพร่จริง
