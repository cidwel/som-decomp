.setcpu "65816"
.segment "CODE"
.org $2875
map_control_0f2875:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
