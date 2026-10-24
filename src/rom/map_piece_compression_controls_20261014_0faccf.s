.setcpu "65816"
.segment "CODE"
.org $ACCF
map_control_0faccf:
    .byte $C1 ; same-value copy count/distance
    .byte $DD ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
