.setcpu "65816"
.segment "CODE"
.org $670C
map_control_0c670c:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
