.setcpu "65816"
.segment "CODE"
.org $ED64
map_control_0fed64:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
