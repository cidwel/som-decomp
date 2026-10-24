.setcpu "65816"
.segment "CODE"
.org $9432
map_control_0e9432:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
