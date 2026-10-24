.setcpu "65816"
.segment "CODE"
.org $018B
map_control_0f018b:
    .byte $E1 ; previous-row copy count
