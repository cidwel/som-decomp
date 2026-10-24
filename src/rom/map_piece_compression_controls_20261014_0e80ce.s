.setcpu "65816"
.segment "CODE"
.org $80CE
map_control_0e80ce:
    .byte $E1 ; previous-row copy count
