.setcpu "65816"
.segment "CODE"
.org $2262
map_control_0e2262:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
