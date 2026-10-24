.setcpu "65816"
.segment "CODE"
.org $4DB5
map_control_0c4db5:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
