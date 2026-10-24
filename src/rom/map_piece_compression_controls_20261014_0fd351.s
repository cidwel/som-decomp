.setcpu "65816"
.segment "CODE"
.org $D351
map_control_0fd351:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
