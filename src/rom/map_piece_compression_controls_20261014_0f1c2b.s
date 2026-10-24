.setcpu "65816"
.segment "CODE"
.org $1C2B
map_control_0f1c2b:
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
