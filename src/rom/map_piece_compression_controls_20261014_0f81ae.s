.setcpu "65816"
.segment "CODE"
.org $81AE
map_control_0f81ae:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
