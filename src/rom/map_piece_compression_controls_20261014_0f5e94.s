.setcpu "65816"
.segment "CODE"
.org $5E94
map_control_0f5e94:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
