.setcpu "65816"
.segment "CODE"
.org $4A06
map_control_0f4a06:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $4B ; distance low bit/count
