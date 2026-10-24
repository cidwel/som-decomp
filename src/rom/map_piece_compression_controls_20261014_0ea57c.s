.setcpu "65816"
.segment "CODE"
.org $A57C
map_control_0ea57c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
