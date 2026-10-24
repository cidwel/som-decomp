.setcpu "65816"
.segment "CODE"
.org $8CEF
map_control_0f8cef:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
