.setcpu "65816"
.segment "CODE"
.org $4BED
map_control_0d4bed:
    .byte $C4 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
