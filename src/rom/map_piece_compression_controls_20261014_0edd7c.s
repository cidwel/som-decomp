.setcpu "65816"
.segment "CODE"
.org $DD7C
map_control_0edd7c:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $AD ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $5F ; distance low bit/count
