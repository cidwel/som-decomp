.setcpu "65816"
.segment "CODE"
.org $AA80
map_control_0faa80:
    .byte $E3 ; previous-row copy count
