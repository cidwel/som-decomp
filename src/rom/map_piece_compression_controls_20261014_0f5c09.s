.setcpu "65816"
.segment "CODE"
.org $5C09
map_control_0f5c09:
    .byte $C6 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A7 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
