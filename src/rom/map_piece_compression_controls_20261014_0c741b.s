.setcpu "65816"
.segment "CODE"
.org $741B
map_control_0c741b:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
