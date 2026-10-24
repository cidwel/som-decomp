.setcpu "65816"
.segment "CODE"
.org $BD85
map_control_0dbd85:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
