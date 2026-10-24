.setcpu "65816"
.segment "CODE"
.org $5881
map_control_0f5881:
    .byte $C4 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
