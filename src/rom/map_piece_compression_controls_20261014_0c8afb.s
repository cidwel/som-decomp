.setcpu "65816"
.segment "CODE"
.org $8AFB
map_control_0c8afb:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
