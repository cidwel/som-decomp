.setcpu "65816"
.segment "CODE"
.org $65AE
map_control_0c65ae:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
