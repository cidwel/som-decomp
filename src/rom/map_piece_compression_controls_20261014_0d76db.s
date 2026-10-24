.setcpu "65816"
.segment "CODE"
.org $76DB
map_control_0d76db:
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
