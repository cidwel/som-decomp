.setcpu "65816"
.segment "CODE"
.org $9214
map_control_0d9214:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
