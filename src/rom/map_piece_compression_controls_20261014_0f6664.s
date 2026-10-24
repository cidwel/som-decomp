.setcpu "65816"
.segment "CODE"
.org $6664
map_control_0f6664:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $CD ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
