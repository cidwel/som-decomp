.setcpu "65816"
.segment "CODE"
.org $4942
map_control_0f4942:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
