.setcpu "65816"
.segment "CODE"
.org $7050
map_control_0f7050:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
    .byte $E4 ; previous-row copy count
