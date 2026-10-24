.setcpu "65816"
.segment "CODE"
.org $BDE3
map_control_0fbde3:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
