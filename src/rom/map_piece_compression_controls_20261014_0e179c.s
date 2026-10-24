.setcpu "65816"
.segment "CODE"
.org $179C
map_control_0e179c:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $CD ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
