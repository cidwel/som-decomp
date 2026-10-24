.setcpu "65816"
.segment "CODE"
.org $AC58
map_control_0fac58:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
