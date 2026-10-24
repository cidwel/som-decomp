.setcpu "65816"
.segment "CODE"
.org $941A
map_control_0e941a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $D2 ; same-value copy count/distance
    .byte $DC ; same-value copy count/distance
