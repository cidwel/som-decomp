.setcpu "65816"
.segment "CODE"
.org $1653
map_control_0e1653:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
