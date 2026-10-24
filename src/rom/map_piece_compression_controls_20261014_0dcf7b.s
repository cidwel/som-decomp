.setcpu "65816"
.segment "CODE"
.org $CF7B
map_control_0dcf7b:
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
