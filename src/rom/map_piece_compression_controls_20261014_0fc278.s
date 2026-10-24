.setcpu "65816"
.segment "CODE"
.org $C278
map_control_0fc278:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9B ; row-distance/count
