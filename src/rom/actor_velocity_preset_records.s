; Actor velocity presets: vx/vy sign-magnitude, vz two's complement; $80 keeps an axis.
; Fourth byte is zero in all28 four-byte records. See docs/maps.md.
.setcpu "65816"
.segment "CODE"
.org $AF05
actor_velocity_preset_records:
    .byte $00, $00, $00, $00 ; preset0
    .byte $01, $80, $80, $00 ; preset1
    .byte $02, $80, $80, $00 ; preset2
    .byte $03, $80, $80, $00 ; preset3
    .byte $04, $80, $80, $00 ; preset4
    .byte $81, $80, $80, $00 ; preset5
    .byte $82, $80, $80, $00 ; preset6
    .byte $83, $80, $80, $00 ; preset7
    .byte $84, $80, $80, $00 ; preset8
    .byte $80, $01, $80, $00 ; preset9
    .byte $80, $02, $80, $00 ; preset10
    .byte $80, $03, $80, $00 ; preset11
    .byte $80, $04, $80, $00 ; preset12
    .byte $80, $81, $80, $00 ; preset13
    .byte $80, $82, $80, $00 ; preset14
    .byte $80, $83, $80, $00 ; preset15
    .byte $80, $84, $80, $00 ; preset16
    .byte $80, $80, $01, $00 ; preset17
    .byte $80, $80, $02, $00 ; preset18
    .byte $80, $80, $03, $00 ; preset19
    .byte $80, $80, $04, $00 ; preset20
    .byte $80, $80, $FF, $00 ; preset21
    .byte $80, $80, $FE, $00 ; preset22
    .byte $80, $80, $FD, $00 ; preset23
    .byte $80, $80, $FC, $00 ; preset24
    .byte $00, $80, $80, $00 ; preset25
    .byte $80, $00, $80, $00 ; preset26
    .byte $80, $80, $00, $00 ; preset27
