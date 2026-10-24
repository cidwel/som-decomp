.setcpu "65816"
.segment "CODE"
.org $CF62
map_control_0dcf62:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
