.setcpu "65816"
.segment "CODE"
.org $8538
map_control_0d8538:
    .byte $EF ; backreference distance high bits
    .byte $99 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
