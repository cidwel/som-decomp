.setcpu "65816"
.segment "CODE"
.org $668D
map_control_0f668d:
    .byte $ED ; backreference distance high bits
    .byte $96 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
