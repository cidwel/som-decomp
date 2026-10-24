.setcpu "65816"
.segment "CODE"
.org $7B32
map_control_0c7b32:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2D ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
