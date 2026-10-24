.setcpu "65816"
.segment "CODE"
.org $6AA3
map_control_0f6aa3:
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
