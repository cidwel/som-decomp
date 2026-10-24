.setcpu "65816"
.segment "CODE"
.org $AF58
map_control_0daf58:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
