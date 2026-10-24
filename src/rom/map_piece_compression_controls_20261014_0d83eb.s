.setcpu "65816"
.segment "CODE"
.org $83EB
map_control_0d83eb:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
