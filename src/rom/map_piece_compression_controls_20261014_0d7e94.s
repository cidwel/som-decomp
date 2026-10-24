.setcpu "65816"
.segment "CODE"
.org $7E94
map_control_0d7e94:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
