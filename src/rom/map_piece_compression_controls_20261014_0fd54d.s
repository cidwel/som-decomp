.setcpu "65816"
.segment "CODE"
.org $D54D
map_control_0fd54d:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $52 ; row-distance/count
