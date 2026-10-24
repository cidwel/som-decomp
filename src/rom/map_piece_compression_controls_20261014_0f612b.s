.setcpu "65816"
.segment "CODE"
.org $612B
map_control_0f612b:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
