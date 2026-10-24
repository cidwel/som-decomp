.setcpu "65816"
.segment "CODE"
.org $BF32
map_control_0fbf32:
    .byte $C4 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
