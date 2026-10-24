.setcpu "65816"
.segment "CODE"
.org $1704
map_control_0c1704:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
