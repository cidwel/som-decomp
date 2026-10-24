.setcpu "65816"
.segment "CODE"
.org $DBB1
map_control_0edbb1:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
