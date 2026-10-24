.setcpu "65816"
.segment "CODE"
.org $1AF6
map_control_0c1af6:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
