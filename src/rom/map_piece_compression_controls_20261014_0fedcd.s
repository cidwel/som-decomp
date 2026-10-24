.setcpu "65816"
.segment "CODE"
.org $EDCD
map_control_0fedcd:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
