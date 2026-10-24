.setcpu "65816"
.segment "CODE"
.org $B71E
map_control_0fb71e:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
