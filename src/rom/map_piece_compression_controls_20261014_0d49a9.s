.setcpu "65816"
.segment "CODE"
.org $49A9
map_control_0d49a9:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
