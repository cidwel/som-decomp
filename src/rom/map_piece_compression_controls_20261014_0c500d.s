.setcpu "65816"
.segment "CODE"
.org $500D
map_control_0c500d:
    .byte $E1 ; previous-row copy count
